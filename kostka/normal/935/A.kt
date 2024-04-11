fun main(args: Array<String>) {
  val n = readLine()!!.toInt()
  var ret = 0
  for(i in 1..n-1) {
    if((n-i) % i == 0) ret++
  }
  println(ret)
}