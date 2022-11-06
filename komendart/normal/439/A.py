n, d = [int(i) for i in input().split()]
t = [int(i) for i in input().split()]

result = -2
time = -10
for i in t:
    time += i + 10
    result += 2

if time > d:
    print(-1)
else:
    print(result + (d - time) // 5)