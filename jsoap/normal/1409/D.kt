import java.io.BufferedReader
import java.io.InputStreamReader

fun digitSum(k: Long): Long {
    var k = k
    var res = 0L
    while (k > 0L) {
        res += k % 10L
        k /= 10L
    }
    return res
}

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        var (n, s) = jin.readLine().split(" ").map { it.toLong() }
        var answer = 0L
        var pow10 = 1L
        while (digitSum(n) > s) {
            val delta = (10L - (n % 10L)) % 10L
            answer += delta * pow10
            n += delta
            pow10 *= 10L
            n /= 10L
        }
        out.appendln(answer)
    }
    print(out)
}