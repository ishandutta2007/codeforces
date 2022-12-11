import java.io.InputStream
import java.io.InputStreamReader
import java.io.BufferedReader

fun main(args: Array<String>) {
	var str : String
    str = readLine()!!
    var start = true
    var comma = false
    var started = false
    for (j in str) {
        if (j in 'a'..'z' || j in 'A'..'Z') {
            if (comma) {
                print(' ')
            }
            started = true
            comma = false
            if (start) {
                if (j in 'a'..'z') {
                    print((j.toInt() - 'a'.toInt() + 'A'.toInt()).toChar())
                } else {
                    print(j)
                }
            } else {
                if (j in 'A'..'Z') {
                    print((j.toInt() - 'A'.toInt() + 'a'.toInt()).toChar())
                } else {
                    print(j)
                }
            }
            start = false
        } else if (j == ',') {
            comma = true
            print(',')
        } else if (j == '.') {
            comma = true
            print('.')
            start = true
        } else if (j == ' ') {
            if (started) {
                comma = true
            }
        }
    }
}