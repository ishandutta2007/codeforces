import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    val n = jin.readLine().toInt()
    val tokenizer = StringTokenizer(jin.readLine())
    var s = tokenizer.nextToken().toLong()
    var prev = s
    val ds = LongArray(n - 1)
    var d = 0L
    for (j in 0..n - 2) {
        val k = tokenizer.nextToken().toLong()
        ds[j] = k - prev
        d += max(0L, ds[j])
        prev = k
    }
    fun answer(): Long {
        var res = s + d
        if (res % 2L != 0L) {
            res++
        }
        return res / 2L
    }
    out.appendln(answer())
    for (j in 1..jin.readLine().toInt()) {
        val (l, r, xs) = jin.readLine().split(" ").map { it.toInt() }
        val x = xs.toLong()
        if (l == 1) {
            s += x
        } else {
            d -= max(0L, ds[l - 2])
            ds[l - 2] += x
            d += max(0L, ds[l - 2])
        }
        if (r != n) {
            d -= max(0L, ds[r - 1])
            ds[r - 1] -= x
            d += max(0L, ds[r - 1])
        }
        out.appendln(answer())
    }
    print(out)
}