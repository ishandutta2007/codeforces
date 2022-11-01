import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val ay = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
    val dp = Array(n + 1) { IntArray(n + 1) { n + 1 } }
    dp[0][0] = 0
    for (a in 1..n) {
        for (b in 0..min(n, ay[a])) {
            dp[a][b] = dp[a - 1][b] + 1
            if (b > 0) {
                dp[a][b] = min(dp[a][b], dp[a][b - 1] + 1)
            }
            if (b == ay[a]) {
                dp[a][b]--
            }
        }
        for (b in n - 1 downTo 0) {
            dp[a][b] = min(dp[a][b], dp[a][b + 1])
        }
    }
    println(dp[n][0])
}