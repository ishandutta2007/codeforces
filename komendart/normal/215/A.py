n = int(raw_input())
a = [int(i) for i in raw_input().split()]
m = int(raw_input())
b = [int(i) for i in raw_input().split()]

max_ = number = 0
for i in a:
    for j in b:
        if j % i == 0:
            if max_ == j / i:
                number += 1
            elif max_ < j / i:
                max_ = j / i
                number = 1

print number