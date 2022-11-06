n = int(input())

result = 0
count = 0
for i in (int(i) for i in input().split()):
    if i == -1 and count == 0:
        result += 1
    else:
        count += i

print(result)