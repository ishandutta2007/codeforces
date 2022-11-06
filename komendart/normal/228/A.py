array = sorted(int(i) for i in raw_input().split())
result = 0
for i in range(3):
    if array[i] == array[i + 1]:
        result += 1
print result