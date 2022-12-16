from math import log2, ceil

n = int(input())
out = 0
n -= 1
for i in range(ceil(log2(n))+1):
    #print(i)
    out += ((n-2**i)//(2**(i+1))+1)*2**i
print(out)