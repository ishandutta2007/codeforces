import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (a, b, x, y, n) = jin.readLine().split(" ").map { it.toLong() }
        val alpha = max(x, a - n)
        val beta = max(y, b - (n - (a - alpha)))
        val delta = max(y, b - n)
        val gamma = max(x, a - (n - (b - delta)))
        out.appendln(min(alpha * beta, gamma * delta))
    }
    print(out)
}