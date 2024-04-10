fun dotProduct(A : Pair<Int, Int>, B : Pair<Int, Int>, C : Pair<Int, Int>) =
    (B.first - A.first) * (C.first - A.first) + (B.second - A.second) * (C.second - A.second)

fun crossProduct(A : Pair<Int, Int>, B : Pair<Int, Int>, C : Pair<Int, Int>) =
    (B.first - A.first) * (C.second - A.second) - (B.second - A.second) * (C.first - A.first)

fun isRight(A : Pair<Int, Int>, B : Pair<Int, Int>, C : Pair<Int, Int>) =
    crossProduct(A, B, C) != 0 && (dotProduct(A, B, C) == 0 || dotProduct(B, A, C) == 0 || dotProduct(C, A, B) == 0)

fun main() {
    val a = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
    val points = listOf(Pair(a[0], a[1]), Pair(a[2], a[3]), Pair(a[4], a[5]))
    val cx = listOf(0, 0, -1, 1)
    val cy = listOf(-1, 1, 0, 0)
    if (isRight(points[0], points[1], points[2])) {
        println("RIGHT")
        return
    }
    else {
        repeat(3) { i ->
            repeat(4) {
                a[2 * i + 0] += cx[it]
                a[2 * i + 1] += cy[it]
                val points = listOf(Pair(a[0], a[1]), Pair(a[2], a[3]), Pair(a[4], a[5]))
                if (isRight(points[0], points[1], points[2])) {
                    println("ALMOST")
                    return
                }
                a[2 * i + 0] -= cx[it]
                a[2 * i + 1] -= cy[it]
            }
        }
    }
    println("NEITHER")
}