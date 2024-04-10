num_s = input()
num = 0

for digit in num_s:
    num *= 2

    if digit == '1':
        num += 1

cnt = 0
cur = 1

while cur < num:
    cur *= 4
    cnt += 1

print(cnt)