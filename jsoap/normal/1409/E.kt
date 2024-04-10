import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val xs = listOf(0) + jin.readLine().split(" ").map { it.toInt() }.sorted()
        jin.readLine()
        val dp = IntArray(n + 1)
        var j2 = 1
        var answer = 0
        for (j1 in 1..n) {
            while (xs[j1] > xs[j2] + k) {
                j2++
            }
            dp[j1] = max(j1 - j2 + 1, dp[j1 - 1])
            answer = max(answer, j1 - j2 + 1 + dp[j2 - 1])
        }
        out.appendln(answer)
    }
    print(out)
}