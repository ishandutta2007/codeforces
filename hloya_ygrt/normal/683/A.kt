import java.util.*
import java.io.*
import java.text.*
import java.math.*
import java.net.*
import java.util.regex.*

  val maxn = 100 * 1000 + 5
   fun main(args:Array<String>) {
  	var input:Scanner = Scanner(System.`in`)
    val a = input.nextInt()
    val x = input.nextInt()
    val y = input.nextInt()
      
    if (x > 0 && y > 0 && x < a && y < a)
    println("0")
    else
    {
      if (x < 0 || y < 0 || x > a || y > a)
      println("2")
      else
      println("1")
    }
  }