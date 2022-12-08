import math

n = int(input())
if n % 2 == 0:
    print(n // 2)
else:
    maxi = n
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            maxi = i
            break
    print(1 + (n - maxi) // 2)