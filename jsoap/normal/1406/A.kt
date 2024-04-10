import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = jin.readLine().split(" ").map { it.toInt() }.sorted()
        var mex1 = 0
        var mex2 = 0
        for (a in ay) {
            if (mex1 == a) {
                mex1++
            } else if (mex2 == a) {
                mex2++
            }
        }
        println(mex1 + mex2)
    }
}