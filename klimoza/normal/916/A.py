x = int(input())
h, m = map(int, input().split())
t = 0
while True:
    if h % 10 == 7 or m % 10 == 7:
        break
    m -= x
    if m < 0:
        m += 60
        h -= 1
    if h < 0:
        h = 23
    t += 1
print(t)