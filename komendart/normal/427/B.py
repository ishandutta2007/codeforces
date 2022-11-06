n, t, c = [int(i) for i in input().split()]

result = 0
danger = -1
for i, v in enumerate(int(i) for i in input().split()):
    if v > t:
        danger = i
    elif i - danger >= c:
        result += 1

print(result)