import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val s = jin.readLine()
        val x = jin.readLine().toInt()
        val t = CharArray(s.length) { j -> if ((j >= x && s[j - x] == '0') || (j + x < s.length && s[j + x] == '0')) '0' else '1' }
        val u = String(CharArray(s.length) { j -> if ((j >= x && t[j - x] == '1') || (j + x < s.length && t[j + x] == '1')) '1' else '0' })
        if (u == s) {
            out.appendln(t)
        } else {
            out.appendln(-1)
        }
    }
    print(out)
}