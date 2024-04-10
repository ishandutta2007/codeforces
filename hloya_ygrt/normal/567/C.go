package main

import "fmt"
import "bufio"
import "strconv"
import "os"

const maxn int = 200000

var (
	reader  = bufio.NewReader(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
	scanner = bufio.NewScanner(os.Stdin)
)

func main() {
	defer writer.Flush()
	scanner.Split(bufio.ScanWords)

	var array[maxn] int64
	var n int
	var k int64

	n = nextInt()
	k = nextInt64()

	var m1 map[int64]int64
	var m2 map[int64]int64
	m1 = make(map[int64]int64)
	m2 = make(map[int64]int64)

	for i := 0; i < n; i++ {
		array[i] = nextInt64()
		m2[array[i]] += 1
	}

	var ans int64 = 0
	for i := 0; i < n; i++ {
		var cur int64 = array[i]
		m2[cur] -= 1

		if cur % k == 0 {
			ans += m1[cur / k] * m2[cur * k]
		}

		m1[cur] += 1
	}

	println(ans)
}

func scan(a ...interface{}) {
	fmt.Fscan(reader, a...)
}

func next() string {
	if !scanner.Scan() {
		panic(scanner.Err())
	}
	return scanner.Text()
}

func nextInt64() int64 {
	n, _ := strconv.ParseInt(next(), 0, 64)
	return n
}

func nextInt() int {
	n, _ := strconv.Atoi(next())
	return n
}

func println(a ...interface{})               { fmt.Fprintln(writer, a...) }
func print(a ...interface{})                 { fmt.Fprint(writer, a...) }
func printf(format string, a ...interface{}) { fmt.Fprintf(writer, format, a...) }