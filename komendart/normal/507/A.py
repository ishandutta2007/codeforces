n, k = [int(i) for i in input().split()]
a = [(int(v), i) for i, v in enumerate(input().split())]

a.sort()
result = []
for v, i in a:
    k -= v
    if k < 0: break
    result.append(i + 1)

result.sort()
print(len(result))
print(' '.join(str(i) for i in result))