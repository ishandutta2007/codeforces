fun main(args: Array<String>) {
  val n = readLine()!!.toInt()
  val texts : MutableList<String> = mutableListOf()
  for(i in 1..n) {
    if(i%2 == 1) {
      texts.add("I hate")
    } else {
      texts.add("I love")
    }
  }
  println(texts.joinToString(" that ")+" it")
}