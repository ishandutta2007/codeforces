import java.io.InputStream
import java.io.InputStreamReader
import java.io.BufferedReader

fun main(args: Array<String>) {

    var cnt = IntArray(3000)
    for (tt in 0..1) {
        var str : String
        str = readLine()!!
        var x = 0
        var first = true
        var negative = false
        for (j in str) {
            if (j == ' ') {
                if (first) {
                    first = false
                } else {
                    if (negative) {
                        x *= -1
                    }
                    cnt[x + 1050] += 1
                }
                x = 0
                negative = false
            } else {
                if (j == '-') {
                    negative = true
                } else {
                
                x *= 10
                x += j.toInt() - '0'.toInt() 
                }
            }
        }
        if (negative) {
                        x *= -1
                    }
        cnt[x + 1050] += 1
    }
    var ans = 0
    for (i in 0 ..2999) {
        if (cnt[i] == 1) {
            ans += 1
        }
    }
    print(ans)
    for (i in 0..2999) {
        if (cnt[i] == 1) {
            print(' ')
            print(i - 1050)
        }
    }
    println()
}