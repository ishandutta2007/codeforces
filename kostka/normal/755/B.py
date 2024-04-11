[n,m] = list(map(int, input().split(" ")))
A = set()
B = set()
for i in range(n):
    A.add(input())
for i in range(m):
    B.add(input())
BOTH = A & B
kA = len(A)
kB = len(B)
kC = len(BOTH)
turn = 1
while True:
    turn = 1-turn
    if kC > 0:
        kC -= 1
        kA -= 1
        kB -= 1
        continue
    if turn == 0:
        if kA > 0:
            kA -= 1
        else:
            print("NO")
            exit(0)
    else:
        if kB > 0:
            kB -= 1
        else:
            print("YES")
            exit(0)