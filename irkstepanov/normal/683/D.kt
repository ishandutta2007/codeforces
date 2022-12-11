import java.util.Scanner;

fun main(args: Array<String>) {
    var (n) = readLine()!!.split('\n').map(String::toInt)
    for (i in 0..n-1) {
        var(n, m, p) = readLine()!!.split(' ').map(String::toInt)
        var flag = false
        for (a in 1..n) {
            for (b in 1..m) {
                if (a * b == p) {
                    flag = true
                }
            }
        }
        if (flag) {
            println("Yes")
        } else {
            println("No")
        }
    }
}