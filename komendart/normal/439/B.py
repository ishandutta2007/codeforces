n, x = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]
c.sort()


time = 0
for i in c:
    time += i * x
    x = max(1, x - 1)

print(time)