import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    repeat(jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val hs = jin.readLine().split(" ").map { it.toInt() }.sorted()
        if (n == 2 || hs.first() == hs.last()) {
            out.appendln(hs.joinToString(" "))
        } else {
            var j = 0
            for (k in 1..n - 2) {
                if (hs[k + 1] - hs[k] < hs[j + 1] - hs[j]) {
                    j = k
                }
            }
            out.appendln((hs.subList(j + 1, n) + hs.subList(0, j + 1)).joinToString(" "))
        }
    }
    print(out)
}