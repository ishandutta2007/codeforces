[n,m] = list(map(int, input().split(" ")))
V = list(map(int, input().split(" ")))
wyn = 0.0
for i in range(m):
    [a,b,c] = list(map(int, input().split(" ")))
    wyn = max(wyn, (V[a-1]+V[b-1])/c)
print(wyn)