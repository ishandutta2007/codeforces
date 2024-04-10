import math
n = int(input())
if(n % 2 == 0):
    print(n // 2)
else:
    x, b = int(math.sqrt(n)), 1
    for i in range(3, x+1, 2):
        if(n % i == 0):
            b = i
            break
    if(b == 1):
        b = n
    print((n - b)//2+1)