import sys
fib = [0]*1000
fib[1] = 2
fib[2] = 3
for i in range(3,1000):
    fib[i] = fib[i-1]+fib[i-2]
n = input()
for i in range(1,1000):
    if fib[i] > n:
        print i - 1
        sys.exit()