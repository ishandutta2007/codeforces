n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]

result = 0
cur = 0
for i in a:
    if i + cur > m:
        cur = i
        result += 1
    else:
        cur += i
if cur > 0: result += 1
print(result)