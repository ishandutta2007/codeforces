fun main(args: Array<String>) {
  readLine()
  val A = readLine()!!.split(' ').map(String::toInt)
  if(1 in A) println("hard")
  else println("easy")
}