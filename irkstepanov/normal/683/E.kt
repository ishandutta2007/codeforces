import java.io.InputStream
import java.io.InputStreamReader
import java.io.BufferedReader

fun main(args: Array<String>) {

    var (n) = readLine()!!.split(' ').map(String::toInt)
    var m = IntArray(n)
    var str : String
    str = readLine()!!
    var x = 0
    var i = 0
    
    for (j in str) {
        if (j == ' ') {
            var cnt = 0
            for (k in 0..n-1) {
                if (m[k] == 0) {
                    cnt += 1
                }
                if (cnt == x + 1) {
                    m[k] = i + 1
                    break
                }
            }
            i += 1
            x = 0
        } else {
            x *= 10;
            x += j.toInt() - '0'.toInt()
        }
    }
    var cnt = 0
            for (k in 0..n-1) {
                if (m[k] == 0) {
                    cnt += 1
                }
                if (cnt == x + 1) {
                    m[k] = i + 1
                    break
                }
            }
            i += 1
            x = 0
    for (t in 0..n-1) {
        print(m[t])
        print(' ')
    }
}