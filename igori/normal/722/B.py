n = int(input())

p = list(map(int, input().split(' ')))
for i in range(n):
    w = input().split(' ')
    cnt = 0
    for s in w:
        for x in s:
            if x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u' or x == 'y':
                cnt += 1
    if cnt != p[i]:
        print("NO")
        exit(0)
print("YES")