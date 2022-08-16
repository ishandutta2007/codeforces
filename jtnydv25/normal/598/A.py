from math import floor, log
for t in range(input()):
    n = input()
    ret = (n*(n+1))/2
    m = 1
    while m <= n:
        ret -= (m<<1)
        m <<=1
    print ret