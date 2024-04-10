import java.io.InputStream
import java.io.InputStreamReader
import java.io.BufferedReader

fun gcd(p: Long, q : Long) : Long
{
    var a = p
    var b = q
    if (a < b) {
        var t = a
        a = b
        b = t
    }
    while (b > 0) {
        a %= b
        var t = a
        a = b
        b = t
    }
    return a
}

fun main(args: Array<String>) {

    var str : String
    str = readLine()!!
    var x : Long
    x = 0
    var y : Long
    y = 0
    var type = 0
    var len1 = 0
    var len2 = 0
    
    for (j in str) {
        if (j == '.') {
            type = 1
            continue
        }
        if (j == '(') {
            type = 2
            continue
        }
        if (j == ')') {
          break
        }
        if (type == 1) {
            x *= 10
            x += j.toInt() - '0'.toInt()
            ++len1
        } 
        if (type == 2) {
            y *= 10
            y += j.toInt() - '0'.toInt()
            ++len2
        }
    }
    
    if (y == 0.toLong())
    {
        var t : Long
        t = 1
        for (i in 0..len1-1) {
            t *= 10
        }
        var g : Long
        g = gcd(x, t)
        print(x / g)
        print('/')
        print(t / g)
    } else {
    var z : Long
    z = x
    for (i in 0..len2-1) {
        z *= 10
    } 
    z += y
    z -= x
    var t : Long
    t = 1
    for (i in 0..len1+len2-1) {
        t *= 10
    }
    var tmp : Long
    tmp = 1
    for (i in 0..len1-1) {
        tmp *= 10
    }
    t -= tmp

    var g : Long
    g = gcd(z, t)
    print(z / g)
    print('/')
    print(t / g)
    }
}