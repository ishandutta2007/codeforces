a, b, c = map(int, input().split())



cntZeroes = 0
tenPw = 1

for i in range(1, 1000):
    tenPw *= 10
    if 1 * b <= a * tenPw:
        break
    cntZeroes += 1



for i in range(1000):
    a = a * 10
a //= b


if c == 0:
    if cntZeroes > 0:
        print(1)
        exit(0)

arr = []
while a > 0:
    arr.append(a%10)
    a //= 10

arr.reverse()
for i in range(len(arr)):
    if arr[i] == c:
        print(cntZeroes + i + 1)
        exit(0)
print(-1)