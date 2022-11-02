n = int(input())
arr = list(map(int, input().split()))
o = sum(arr)
for i in range(max(arr), 10 ** 5):
    if i * n - o > o:
        print(i)
        break