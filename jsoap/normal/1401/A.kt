import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        var answer = abs(n - k)
        if (n > k) {
            if (n % 2 == k % 2) {
                answer = 0
            } else {
                answer = min(answer, 1)
            }
        }
        out.appendln(answer)
    }
    print(out)
}