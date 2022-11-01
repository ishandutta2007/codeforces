import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, k) = jin.readLine().split(" ").map { it.toInt() }
    val s = " " + jin.readLine()
    val t = jin.readLine()
    if (t[0] == t[1]) {
        val amt = min(n, s.count { it == t[0] } + k)
        println((amt * (amt - 1)) / 2)
    } else {
        val dp = Array(n + 1) { Array(k + 1) { IntArray(n + 1) { -1 } } }
        dp[0][0][0] = 0
        var answer = 0
        for (a in 1..n) {
            for (b in 0..k) {
                for (c in 0..n) {
                    if (s[a] == t[0]) {
                        if (c > 0 && dp[a - 1][b][c - 1] != -1) {
                            dp[a][b][c] = dp[a - 1][b][c - 1]
                        }
                        if (b > 0 && dp[a - 1][b - 1][c] != -1) {
                            dp[a][b][c] = max(dp[a][b][c], dp[a - 1][b - 1][c] + c)
                        }
                    } else if (s[a] == t[1]) {
                        if (dp[a - 1][b][c] != -1) {
                            dp[a][b][c] = dp[a - 1][b][c] + c
                        }
                        if (b > 0 && c > 0 && dp[a - 1][b - 1][c - 1] != -1) {
                            dp[a][b][c] = max(dp[a][b][c], dp[a - 1][b - 1][c - 1])
                        }
                    } else {
                        if (dp[a - 1][b][c] != -1) {
                            dp[a][b][c] = dp[a - 1][b][c]
                        }
                        if (b > 0 && c > 0 && dp[a - 1][b - 1][c - 1] != -1) {
                            dp[a][b][c] = max(dp[a][b][c], dp[a - 1][b - 1][c - 1])
                        }
                        if (b > 0 && dp[a - 1][b - 1][c] != -1) {
                            dp[a][b][c] = max(dp[a][b][c], dp[a - 1][b - 1][c] + c)
                        }
                    }
                    answer = max(answer, dp[a][b][c])
                }
            }
        }
        println(answer)
    }
}