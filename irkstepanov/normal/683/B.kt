import java.io.InputStream
import java.io.InputStreamReader
import java.io.BufferedReader

fun main(args: Array<String>) {
    var(n) = readLine()!!.split(' ').map(String::toInt)
    var name = Array(n, {""})
    var h = IntArray(n)
    for (i in 0..n-1) {
        val str = readLine()!!
        for (j in str) {
            if (j in '0'..'9') {
                h[i] *= 10
                h[i] += j.toInt() - '0'.toInt()
            } else if (j != ' ') {
                name[i] += j.toString()
            }
        }
    }
    for (i in 0..n-2) {
        for (j in 0..n-2) {
            if (h[j] > h[j + 1]) {
                val str = name[j]
                val hei = h[j]
                name[j] = name[j + 1]
                h[j] = h[j + 1]
                name[j + 1] = str
                h[j + 1] = hei
            }
        }
    }
    for (i in 0..n-1) {
        println(name[i])
    }
}