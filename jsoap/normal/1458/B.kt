import kotlin.math.max
import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val dp = Array(n + 1) { IntArray(10001) { -1 } }
    dp[0][0] = 0
    var total = 0
    for (j in 1..n) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        total += b
        for (x in n downTo 1) {
            for (k in 0..10000) {
                if (k >= a && dp[x - 1][k - a] != -1) {
                    dp[x][k] = max(dp[x][k], dp[x - 1][k - a] + b)
                }
            }
        }
    }
    for (x in 1..n) {
        var res = 0
        for (k in 0..10000) {
            if (dp[x][k] != -1) {
                res = max(res, min(2 * k, total + dp[x][k]))
            }
        }
        println(res.toDouble() / 2.0)
    }
}