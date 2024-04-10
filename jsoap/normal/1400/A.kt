import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        jin.readLine()
        val s = jin.readLine()
        for (j in s.indices step 2) {
            out.append(s[j])
        }
        out.appendln()
    }
    print(out)
}