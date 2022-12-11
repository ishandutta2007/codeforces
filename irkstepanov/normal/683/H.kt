import java.io.InputStream
import java.io.InputStreamReader
import java.io.BufferedReader

fun main(args: Array<String>) {
    var (koll, k) = readLine()!!.split(' ').map(String::toLong)
    var n = koll.toInt()
    var m = IntArray(n)
    var str : String
    str = readLine()!!
    var x = 0
    var i = 0
    for (j in str) {
        if (j == ' ') {
            m[x - 1] = i
            x = 0
            i += 1
        } else {
            x *= 10
            x += j.toInt() - '0'.toInt()
        }
    }
    m[x - 1] = i
    x = 0
    i += 1
    
    var ans = IntArray(n)
    var g = IntArray(n, {0})
    var cnt = 0
    for (i in 0..n-1) {
        if (g[i] == 0) {
            ++cnt
            g[i] = cnt
            var curr = m[i]
            var len = 1
            while (curr != i) {
                g[curr] = cnt
                ++len
                curr = m[curr]
            }
            var tt = (k % len.toLong()).toInt()
            var l = i
            var r = i
            for (j in 0..tt - 1) {
                r = m[r]
            }
            ans[l] = r + 1
            l = m[l]
            r = m[r]
            ans[l] = r + 1
            while (l != i) {
                l = m[l]
                r = m[r]
                ans[l] = r + 1
            }
        }
    }
    for (i in 0..n-1) {
        print(ans[i])
        print(' ')
    }
}