import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (a, b) = jin.readLine().split(" ").map { it.toLong() }
        out.appendln((abs(a - b) + 9L) / 10L)
    }
    print(out)
}