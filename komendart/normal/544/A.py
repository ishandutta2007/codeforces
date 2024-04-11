k = int(input())
s = input()
liters = set(chr(ord('a') + i) for i in range(26))
result = []
for i in s:
    if i in liters:
        result.append(i)
        liters.remove(i)
    else:
        result[-1] += i

if len(result) < k:
    print("NO")
else:
    while len(result) != k:
        t = result.pop()
        result[-1] += t
    print("YES")
    print('\n'.join(result))