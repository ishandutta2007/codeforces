n, k = [int(i) for i in input().split()]

a = [int(i) for i in input().split()]

a.sort(key=abs, reverse=True)

result = 0
for i in a:
    if k > 0 and i < 0:
        result -= i
        k -= 1
    else:
        result += i

if k % 2 == 1:
    result -= 2 * abs(a[-1])

print(result)