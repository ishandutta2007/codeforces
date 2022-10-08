buf = input().split(" ")
n = int(buf[0])
k = int(buf[1])

czas = 0
buf = input().split(" ")
for i in range(n):
    t = int(buf[i])
    czas += t

czas += (n-1)*10
#print(czas)
if czas > k:
    print(-1)
else:
    print((k-czas) // 5 + 2*(n-1))