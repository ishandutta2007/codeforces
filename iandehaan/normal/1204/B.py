n, l, r = map(int, input().split())
sm = 0
curr = 1
for _ in range(l):
    sm += curr
    curr *= 2
curr //= 2

for _ in range(n-l):
    sm += 1

sm2 = 0
curr2 = 1
for _ in range(r):
    sm2 += curr2
    curr2 *= 2
curr2 //= 2

for _ in range(n-r):
    sm2 += curr2
print(sm, sm2)