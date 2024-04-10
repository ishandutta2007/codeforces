import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = jin.readLine().split(" ").map { it.toLong() }.sorted()
        var answer = if (0L in ay) 0L else Long.MIN_VALUE
        for (a in 0..5) {
            var pos = 1L
            for (j in 0 until a) {
                pos *= ay[j]
            }
            for (j in 1..5 - a) {
                pos *= ay[n - j]
            }
            answer = max(answer, pos)
        }
        out.appendln(answer)
    }
    print(out)
}