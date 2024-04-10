import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val rooks = IntArray(n + 1)
        for (j in 1..m) {
            val (x, y) = jin.readLine().split(" ").map { it.toInt() }
            rooks[x] = y
        }
        var answer = rooks.withIndex().count { (x, y) -> y != 0 && y != x }
        for (x in 1..n) {
            if (rooks[x] != 0 && rooks[x] != x) {
                var y = rooks[x]
                rooks[x] = 0
                while (y != x && y != 0) {
                    val prev = y
                    y = rooks[y]
                    rooks[prev] = 0
                }
                if (y == x) {
                    answer++
                }
            }
        }
        out.appendln(answer)
    }
    print(out)
}