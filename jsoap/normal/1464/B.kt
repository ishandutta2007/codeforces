import kotlin.math.min

fun main() {
    val s = readLine()!!
    val (x, y) = readLine()!!.split(" ").map { it.toLong() }
    println(min(solve(s, x, y), solve(s.replace('0', '2').replace('1', '0').replace('2', '1'), y, x)))
}

fun solve(s: String, x: Long, y: Long): Long {
    var curr = 0L
    var zeros = 0L
    var ones = 0L
    for (bit in s) {
        curr += if (bit == '1') {
            ones++
            zeros * x
        } else {
            zeros++
            ones * y
        }
    }
    var answer = curr
    var zerosAfter = zeros
    var onesAfter = ones
    var zerosBefore = 0L
    var onesBefore = 0L
    for (bit in s) {
        if (bit == '0') {
            zerosAfter--
            zerosBefore++
        } else if (bit == '1') {
            onesAfter--
            onesBefore++
        } else {
            zerosAfter--
            curr -= onesBefore * y
            curr -= onesAfter * x
            curr += zerosBefore * x
            curr += zerosAfter * y
            onesBefore++
            answer = min(answer, curr)
        }
    }
    return answer
}