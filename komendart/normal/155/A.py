raw_input()
array = [int(i) for i in raw_input().split()]
number = 0
max = min = array[0]
for i in array:
    number += 1
    if i > max: max = i
    elif i < min: min = i
    else: number -= 1
print number