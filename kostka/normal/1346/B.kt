fun main(args: Array<String>) {
  val t = readLine()!!.toInt()
  for(ti in 1..t) {
    var (n, k1, k2) = readLine()!!.split(' ').map(String::toInt)
    val ex = readLine()!!
    val lectures : MutableList<Int> = mutableListOf(0)
    for(i in 1..n) {
      if(ex[i-1] != '0') {
        lectures.add(minOf(k2-lectures[i-1], k1))
      } else {
        lectures.add(0)
      }
    }
    var sum = 0
    for(i in 1..n) sum += lectures[i]
    println(sum)
  }
}