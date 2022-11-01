import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val s = jin.readLine()
        val freq = IntArray((2 * s.length) + 2)
        var curr = s.length
        for (bit in s) {
            when (bit) {
                '0' -> {
                    freq[curr]++
                    curr--
                }
                '1' -> {
                    curr++
                    freq[curr]++
                }
            }
        }
        val answer = StringBuilder()
        val stack = Stack<Int>()
        stack.push(s.length)
        while (stack.isNotEmpty()) {
            val a = stack.peek()
            if (freq[a] > 0) {
                freq[a]--
                stack.push(a - 1)
            } else if (freq[a + 1] > 0) {
                freq[a + 1]--
                stack.push(a + 1)
            } else {
                stack.pop()
                if (stack.isNotEmpty()) {
                    answer.append(if (stack.peek() > a) 0 else 1)
                }
            }
        }
        out.appendln(answer.reversed())
    }
    print(out)
}