n = int(input())
arr = list(map(int, input().split()))
f = True
for i in range(n):
    if arr[i]:
        f = False
        break
if f:
    print('EASY')
else:
    print('HARD')