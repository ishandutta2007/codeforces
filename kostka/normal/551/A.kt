fun main(args: Array<String>) {
  readLine()
  val R = readLine()!!.split(' ').map(String::toInt)
  for(r in R) {
    print("${1 + R.filter({it > r}).count()} ")
  }
  println()
}