import kotlin.math.abs

fun main() {
    var t = readLine()!!.substringAfter(' ').toLong()
    val s = readLine()!!.map { it - 'a' }
    t -= 1L shl s.last()
    t += 1L shl s[s.size - 2]
    val freq = LongArray(62)
    for (k in s.subList(0, s.size - 2)) {
        t += 1L shl k
        freq[k + 1]++
    }
    for (k in 0..60) {
        if (abs(t) % (1L shl (k + 1)) != 0L) {
            if (freq[k] == 0L) {
                println("nO")
                return
            }
            freq[k]--
            t -= 1L shl k
        }
        freq[k + 1] += freq[k] / 2L
    }
    println("yEs")
}