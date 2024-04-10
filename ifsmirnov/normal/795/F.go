package main

import (
    "fmt"
)

func main() {
    var n int
    fmt.Scan(&n)
    a := make([]int, n, n)
    for i := 0; i < n; i++ { fmt.Scan(&a[i]) }
    c := make([]int, n, n)
    for i := 0; i < n; i++ { c[i] = 0 }
    for k := 0; k < n*7; k++ {
              if k%7 != 6 {
                    c[k%n] += 1
            if c[k%n] == a[k%n] {
                fmt.Println(k%n+1)
                return
            }
        }
    }
    mx := 1000000000
    for i := 0; i < n; i++ {
        if c[i] == 0 { continue }
        t := (a[i] - 1) / c[i]
        if t < mx { mx = t }
    }
    for i := 0; i < n; i++ {
        c[i] *= mx
    }
    for k := 0; k < n*7; k++ {
        if k%7 != 6 {
            c[k%n] += 1
            if c[k%n] == a[k%n] {
                fmt.Println(k%n+1)
                return
            }
        }
    }
}