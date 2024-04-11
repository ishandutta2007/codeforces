buf = input().split(" ")
n = int(buf[0])
k = int(buf[1])

buf = input().split(" ")
for i in range(n):
    buf[i] = int(buf[i])
buf = sorted(buf)

wyn = 0
for i in range(n):
    wyn += buf[i]*k
    k = max(1, k-1)
    
print(wyn)